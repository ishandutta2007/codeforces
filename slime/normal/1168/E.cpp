#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define vt vector<int>
#define maxn 4130
#define ll long long
#define ld double
using namespace std;
int fl[maxn];
int a[maxn];
int p[maxn], q[maxn], pl[maxn]; 
int nu[maxn], ncnt;
int nr[maxn], ucnt;
int main()
{
	int k;
	cin>>k;
	int n = (1 << k);
	int ns = 0;
	for(int i = 0; i < n; i++)
		cin>>a[i], 
		ns ^= a[i];
	memset(p, -1, sizeof(p));
	memset(q, -1, sizeof(q));
	if(ns)
	{
		cout<<"Fou"<<endl;
		return 0;
	}
	while(1)
	{
		memset(pl, -1, sizeof(pl));
		memset(fl, 0, sizeof(fl));
		for(int i = 0; i < n; i++)
			if(p[i] != -1)
				fl[p[i]] = 1, 
				pl[q[i]] = i;
		ncnt = 0;
		ucnt = 0;
		for(int i = 0; i < n; i++)
			if(!fl[i]) nu[ncnt++] = i;
		for(int i = 0; i < n; i++)
			if(p[i] == -1)
				nr[ucnt++] = i;
		if(!ncnt) break;
		//cout<<ncnt<<endl;
		int s = rand() % ucnt;
		int i = nr[s];
		for(int j = 0; j < ncnt; j++)
		{
			int ed = nu[j] ^ a[i];
			if(pl[ed] == -1)
			{
				p[i] = nu[j], 
				q[i] = ed;
				break;
			}
		}
		if(p[i] == -1)
		{
			int nid = rand() % ncnt;
			p[i] = nu[nid];
			int ed = nu[nid] ^ a[i];
			p[pl[ed]] = q[pl[ed]] = -1;
			q[i] = ed;
		}
	}
	cout<<"Shi"<<endl;
	for(int i = 0; i < n; i++)	
		cout<<p[i]<<" ";
	cout<<endl;
	for(int i = 0; i < n; i++)
		cout<<q[i]<<" ";
	cout<<endl;
	return 0;
} 
/*5 100
4 1 2 3 5
3
1 2 3 6
1 1 5 1
3 2 4
*/