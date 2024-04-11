//In the name of God
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int Maxn = 2e5 + 9;
int p1[Maxn],p2[Maxn];
int t[4 * Maxn];
int ans1[Maxn],ans2[Maxn];
int arr[Maxn],out[Maxn];
int n;
void update(int id,int x,int v = 1,int b = 0,int e = n-1){
	if(b == e){
		t[v] = x;
		return;
	}
	int mid = b + e >> 1,l = v << 1, r = l | 1;
	if(mid + 1 > id)
		update(id,x,l,b,mid);
	else
		update(id,x,r,mid+1,e);
	t[v] = t[l] + t[r];
	return;
}
int query(int i,int j,int v = 1,int b = 0,int e = n-1){
	if(j < i)
		return 0;
	if(j < b || e < i)
		return 0;
	if(i <= b && e <= j)
		return t[v];
	int mid = b + e >> 1,l = v << 1,r = l | 1;
	return query(i,j,l,b,mid) + query(i,j,r,mid+1,e);
}
void get(int *p,int *ans){
	memset(t,0,sizeof t);
	for(int i = 0; i < n;i++){
		int cur = p[i];
		int came = query(0,cur);
		ans[i] = cur - came;
		update(cur,1);
	}
	return;
}
bool check(int x,int pl){
//	cerr << x << ' ' << pl << ' ' << query(0,pl) << " This is check" << endl;
	if(query(0,pl) >= x)
		return 1;
	return 0;
}
int bs(int x,int l = 0,int r = n-1){
	int mid = l + r >> 1;
//	cerr << l << ' ' << r << ' ' << check(x,mid) << endl;
	if(l == r)
		return l;
	if(check(x,mid))
		return bs(x,l,mid);
	return bs(x,mid+1,r);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i = 0; i < n;i++){
		cin >> p1[i];
	}
	for(int i = 0; i < n;i++)
		cin >> p2[i];
	get(p1,ans1);
	get(p2,ans2);
	for(int i = n-1; i + 1;--i){
		arr[i] += ans1[i] + ans2[i];
		if(i)
			arr[i-1] += arr[i] / (n-i);
		arr[i] %= n-i;
		arr[i]++;
	}
	for(int i = 0; i < n;i++){
		int cur = bs(arr[i]);
		update(cur,0);
		cout << cur << ' ';
	}
	cout << endl;
	return 0;
}