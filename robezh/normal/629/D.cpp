#include<cstdio>
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

typedef long long ll;

const int N = 131072;
const double PI = 3.141592653589;

map<ll, int> M;

ll dat[2 * N];
ll num[100050];
ll snum[100050];

void init_dat(int x, int l, int r) {
    if(l == r) {
        dat[x] = num[l];
        return ;
    }
    int mid = (l + r) / 2;
    init_dat(x*2+1,l,mid);
    init_dat(x*2+2,mid+1,r);
    dat[x] = max(dat[x*2+1], dat[x*2+2]);
}

void update(int a, int x, int l, int r, ll k){
	if(r < a || l > a) return ;
	if(a <= l && r <= a){
		dat[x] = k;
		return ;
	}
	
	int mid = (l + r) / 2;
	update(a, x*2+1, l, mid , k);
	update(a, x*2+2, mid+1, r, k);
	
	dat[x] = max(dat[x*2+1], dat[x*2+2]);
}

ll query(int a, int b, int x, int l, int r){
	if(r < a || l > b) return 0;
	if(a <= l && r <= b) return dat[x];
	
	int mid = (l + r) / 2;
	ll left = query(a,b,x*2+1,l,mid);
	ll right = query(a,b,x*2+2,mid+1,r);
	
	return max(left, right);
}


int main() {
    int n;
    int a,b;
    scanf("%d", &n);
    init_dat(0,0,n-1);
    for(int i = 0; i < n; i++){
    	scanf("%d%d", &a, &b);
    	snum[i] = num[i] = (ll)a * a * b;
	}
	sort(snum, snum+n);
	for(int i = 0; i < n; i++){
		M[snum[i]] = i;
	}
	for(int i = 0; i < n; i++){
		int index = M[num[i]];
		ll maxleft = query(0,index-1,0,0,n-1);
		update(index,0,0,n-1,maxleft+num[i]);
	}
	double res = (double)query(0, n-1, 0, 0, n-1) * PI;
	printf("%.8lf", res);
	
	

}