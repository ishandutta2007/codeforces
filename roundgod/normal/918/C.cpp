#include<bits/stdc++.h>
#define F first
#define S second
#define MAXN 100005
using namespace std;
int n,k;
string str;
int main()
{
	cin>>str;
	n=str.size();
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int l=0,r=0,ques=0,minl=0;
		for(int j=i;j<n;j++)
		{
			if(str[j]=='(') l++; else if(str[j]==')') r++; else ques++;
			if(str[j]=='(') minl++; else minl=max(0,minl-1); 
			if(r>l+ques) break;
			if(max(l-r,r-l)<=ques&&(l+r+ques)%2==0&&minl==0) ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}