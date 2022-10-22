#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 520;

struct segtree{
	
	int size;
	vector<int> values;
	
	int NORMAL_item = 0;
	
	int single(int v){
		return v;
	}
	
	int merge(int a , int b){
		return max(a , b);
	}
	
	void init(int n){
		size = 1;
		while(size < n) size *= 2;
		values.assign(2 * size - 1 , NORMAL_item);
	}
	
	void build(vector<int> &a , int x , int lx , int rx){
		if(rx - lx == 1){
			if(lx < a.size()) values[x] = single(a[lx]);
			return;
		}
		int m = (lx + rx) / 2;
		build(a , 2 * x + 1 , lx , m); build(a , 2 * x + 2 , m , rx);
		values[x] = merge(values[2 * x + 1] , values[2 * x + 2]);
		return;
	}
	
	void build(vector<int> &a){
		build(a , 0 , 0 , size);
	}
	
	void set(int i , int v , int x , int lx , int rx){
		if(rx - lx == 1){
			values[x] = single(v);
			return;
		}
		int m = (rx + lx) / 2;
		if(i < m){
			set(i , v , 2 * x + 1 , lx , m);
		} else {
			set(i , v , 2 * x + 2 , m , rx);
		}
		values[x] = merge(values[2 * x + 1] , values[2 * x + 2]);
	}
	
	void set(int i , int v){
		set(i , v , 0 , 0 , size);
		return;
	}
	
	int calc(int l , int r , int x , int lx , int rx){
		if(lx >= r || rx <= l) return NORMAL_item;
		if(lx >= l && rx <= r){
			return values[x];
		}
		int m = (lx + rx) / 2;
		int i1 = calc(l , r , 2 * x + 1 , lx , m) , i2 = calc(l , r , 2 * x + 2 , m , rx);
		return merge(i1 , i2); 
	}
	
	int calc(int l , int r){
		return calc(l , r , 0 , 0 , size);
	}
	
};

int dp[MAX_N][MAX_N] , a[MAX_N] , b[MAX_N] , p[MAX_N];
vector<int> v;
vector< pair<int , int> > s;

int main(){
    segtree st[MAX_N];
    int n , m , o;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        s.push_back( {a[i] , 100000 - i} );
    }
    sort(s.begin() , s.end());
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(s[j] == make_pair(a[i] , 100000 - i)){
                p[i] = j;
                break;
            }
        }
    }
    cin >> m;
    for(int i = 0 ; i < m ; i++){
        cin >> b[i];
		st[i].init(n);
    }
    for(int i = 0 ; i < n ; i++){
        dp[i][0] = (a[i] == b[0]);
    }
    for(int j = 1 ; j < m ; j++){
        for(int i = 0 ; i < n ; i++){
            if(a[i] != b[j]){
                dp[i][j] = dp[i][j - 1];
                st[j].set(p[i] , dp[i][j]);
            } else {
                int z = st[j].calc(0 , p[i]);
                dp[i][j] = z + 1;
                st[j].set(p[i] , dp[i][j]);
            }
        }
    }
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        if(dp[i][m - 1] >= ans){
			ans = dp[i][m - 1];
			o = i;
		}
    }
    cout << ans << "\n";
	int x = o , y = m - 1;
	while(y > 0 && dp[x][y] == dp[x][y - 1]){
		y--;
	}
	while(x >= 0 && y > 0 && dp[x][y] > 1){
		v.push_back(a[x]);
		for(int i = x - 1 ; i >= 0 ; i--){
			if(a[i] < a[x] && dp[i][y] == dp[x][y] - 1){
				x = i;
				break;
			}
		}
		while(y > 0 && dp[x][y] == dp[x][y - 1]){
			y--;
		}
	}
	v.push_back(a[x]);
	reverse(v.begin() , v.end());
	for(int i = 0 ; i < ans ; i++){
		cout<<v[i]<<" ";
	}
	cout<<"\n";
    return 0;
}