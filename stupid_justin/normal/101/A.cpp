#include<bits/stdc++.h>
using namespace std;
struct node
{
	char ch;
	int num;
	int del;
}a[26];
int cha[26];
bool vis[26];
bool cmp(node x,node y)
{
	return x.num<y.num;
}
string str;
int cnt;
int main()
{
	int k;
	cin>>str;cin>>k;
	int n=str.length();
	for (int i=0;i<26;i++) a[i].ch=char(int('a')+i);
	for (int i=0;i<n;i++)
		a[int(str[i])-int('a')].num++;
	for (int i=0;i<26;i++) if (a[i].num!=0) cnt++;
	sort(a,a+26,cmp);
	for (int i=0;i<26;i++)
	{
		if (a[i].num<=k) a[i].del=a[i].num,k-=a[i].del;
		if (a[i].del!=0) cnt--;
	}
		
	for (int i=0;i<26;i++) cha[int(a[i].ch)-int('a')]=a[i].del;
	cout<<cnt<<endl;
	for (int i=0;i<n;i++)
	{
		if (cha[int(str[i])-int('a')]==0) cout<<str[i];
		else cha[int(str[i])-int('a')]--;
	}
}