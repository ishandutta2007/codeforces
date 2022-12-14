//In the name of God
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <sstream>
using namespace std;
vector<int> arr;
vector<int> cur;
const int Maxn = 1e5 + 9;
int last[Maxn],t[Maxn],n;
int ans[Maxn];
void update(int id,int x,int v = 1,int b = 0,int e = n - 1){
	if(b == e){
		t[v] = x;
		return;
	}
	int mid = b + e >> 1,l = v << 1,r = l | 1;
	if(mid + 1 > id)
		update(id,x,l,b,mid);
	else
		update(id,x,r,mid+1,e);
	t[v] = t[l] + t[r];
	return;
}
int query(int i,int j,int v = 1,int b = 0,int e = n-1){
	int mid = b + e >> 1, l = v << 1,r = l | 1;
	if(j < b || i > e)
		return 0;
	if(i <= b && e <= j)
		return t[v];
	return query(i,j,l,b,mid) + query(i,j,r,mid+1,e);
}
int to_int(string S){
	stringstream ss;
	ss << S;
	int ret = 0;
	ss >> ret;
	return ret;
}
int main(){
	ios_base::sync_with_stdio(0);
	int rec,time;
	cin >> n >> rec >> time;
	for(int i = 0; i < n;i++){
		string S;
		cin >> S;
		string P = "";
		P += S[0];
		P += S[1];
		int hours = to_int(P);
		P = "";
		P += S[3];
		P += S[4];
		int minutes = to_int(P);
		P = "";
		P += S[6];
		P += S[7];
		int second = to_int(P);
		int t = hours * 3600 + minutes * 60 + second;
		arr.push_back(t);
	}
	bool flag = 0;
	int x = 0;
	int last_user = -1;
	memset(last,-1,sizeof last);
	for(int i = 0; i < n;i++){
		int now = arr[i];
		int pl = lower_bound(cur.begin(),cur.end(),now) - cur.begin();
		int id = -1;
		int pnum = query(pl,i);
		if(pnum == rec-1)
			flag = 1;
		if(pnum == rec){
			id = last_user;
			flag = 1;
		}else{
			id = x++;
		}
		if(last[id] != -1){
			update(last[id],0);
		}
		ans[i] = id;
		last[id] = i;
		update(i,1);
		cur.push_back(now + time - 1);
		last_user = id;
	}
	if(!flag){
		cout << "No solution" << endl;
		return 0;
	}
	cout << x << "\n";
	for(int i = 0; i < n;i++)
		cout << ans[i] + 1 << "\n";
	return 0;
}