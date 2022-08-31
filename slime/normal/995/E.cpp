#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define maxn 1000005
#define ll long long
using namespace std;
ll p;
ll ksm(ll a, ll b)
{
	if(!b) return 1;
	ll ns = ksm(a, b >> 1);
	ns = ns * ns % p;
	if(b & 1) ns = ns * a % p;
	return ns;
}
map<int, int> pre[2], cal[2];
map<int, int> fl[2]; 
int q[maxn], th[maxn];	
int fr = 0, ed = 0;
bool flag = 0;	
int u[2];
int ns[maxn], ncnt;
void upd(int a, int b)
{	
	if(a == u[b]) return;	
//	cout<<a<<" "<<b<<" "<<cal[b][a]<<endl;
	ns[ncnt++] = cal[b][a];
	upd(pre[b][a], b);
}
void push(int a, int b, int c)
{

	if(fl[b][a]) return;	
	fl[b][a] = 1, pre[b][a] = c;
	if((c + 1) % p == a) cal[b][a] = 1;
	else if((c - 1 + p) % p == a) cal[b][a] = 2;
	else cal[b][a] = 3;
	q[ed] = a, th[ed] = b, ed++;	
//	cout<<"PUSH"<<a<<" "<<b<<" "<<c<<endl;
	ll bg = u[0];
	if(fl[b ^ 1][a])
	{
	//	cout<<"!!!"<<a<<endl;
		upd(a, 0);
		int lcnt = ncnt;
		for(int i = 0; lcnt - 1 - i > i; i++)
			swap(ns[i], ns[lcnt - 1 - i]);
	//	cout<<"AFT"<<endl;
		upd(a, 1);
		printf("%d\n", ncnt);
		for(int i = 0; i < ncnt; i++)
		{
			if(i >= lcnt && ns[i] <= 2)
				ns[i] = 3 - ns[i];
			printf("%d ", ns[i]);
			if(ns[i] == 1) bg = (bg + 1) % p;
			else if(ns[i] == 2) bg = (bg - 1) % p;
			else bg = ksm(bg, p - 2);
		//	cout<<bg<<endl;
		}
		flag = 1;
	}	

	return;
}
int main()
{

	scanf("%d%d%lld", &u[0], &u[1], &p);
	push(u[0], 0, 0), push(u[1], 1, 0);
	while(fr < ed)
	{
		if(flag) break;
		for(int i = 1; i <= 3; i++)
		{
		//	cout<<"PUSH"<<i<<" "<<q[fr]<<endl;
			int edx = q[fr];
			if(i == 1) edx = (edx + 1) % p;
			else if(i == 2) edx = (edx - 1) % p;
			else edx = ksm(edx, p - 2);
			push(edx, th[fr], q[fr]);
			if(flag) break;
		}
		 
		fr++;
	}
	return 0;
} 
/*
10000000 112312332 1000000007*/