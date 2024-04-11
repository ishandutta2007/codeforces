#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[2000009];
int F[2000009],b[2000009],used[2000009];

vector<pair<int,int> > v[2000009];
int ans[2000009];
vector<int> path;
void dfs(int x) {
	while(v[x].size()) {
		int y = v[x].back().first, E = v[x].back().second;
		v[x].pop_back();
		if(F[abs(E)]) continue;
		F[abs(E)] = 1;
		dfs(y);
	}
	path.push_back(x);
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    srand(time(0));
    int n;
    cin >> n;
    for(int i =1; i <= n; i++){
        used[i]  =0;
        cin >> a[2*i-1] >> a[2*i];
      
    }
    int lo = 0, hi = 20;
    while(lo <= hi){
        int mid = (lo + hi + 1)/2;
        for(int i = 1; i <= 2*n; i++){
 
            b[i] = (a[i] & ((1<<mid)-1));
         
        }
        path.clear();
        for(int i = 0; i < (1<<mid); i++)
            v[i].clear();
        for(int i = 1; i <= n; i++){
            v[b[2*i]].push_back({b[2*i-1],i});
            v[b[2*i-1]].push_back({b[2*i],-i});
            F[i] = 0;
        }
        int ok = 1;
        for(int i = 0; i < (1<<mid); i++){
            if(v[i].size() % 2) ok = 0;
        }
        if(!ok) {hi = mid - 1; continue;}
        dfs(b[1]);
        if(path.size() != n + 1) {hi = mid -1; continue;}
        if(lo == hi) break;
        lo = mid;
 
 
    }
    cout<<lo<<endl;
    vector<pair<pair<int,int>,int> > A,B;
    for(int i = 1; i <= n; i++){
        int x = path[i-1];
        int y = path[i]; 
        if(x > y) 
        A.push_back({{x,y},i});
        else A.push_back({{y,x},-i});
 
    }
    for(int i = 1; i <= n; i++){
        
         int x = b[2*i];
        int y = b[2*i-1]; 
        if(x > y) 
        B.push_back({{x,y},i});
        else B.push_back({{y,x},-i});
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    for(int i = 0; i  < A.size(); i++){
        int x = A[i].second,y  = B[i].second;
        if(x > 0 && y > 0 || x < 0 && y < 0) ans[abs(x)] = abs(y);
        else ans[abs(x)] = -abs(y);
    }
    for(int i = 1; i <= n; i++){
        int z = ans[i];
        if(z > 0) cout<<2*z<<" "<<2*z-1<<" ";
        else cout<<-2*z-1<<" "<<-2*z<<" ";
    }
    cout<<endl;
 
}