#include<bits/stdc++.h>
 
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define Unique(x) x.erase(unique(all(x)),x.end());
 
using namespace std;
 
const int dx[]={-1,0,1,0};
const int dy[]={0,-1,0,1};
 
const int Days[]={-1,31,28,31,30,31,30,31,31,30,31,30,31};
 
inline int read()
{
	#define gc getchar
	int ans=0;
	bool f=1;
	char ch=gc();
	
	while(!isdigit(ch))f^=ch=='-',ch=gc();
	
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	
	return f?ans:-ans;
	
	#undef gc
}
 
typedef long long ll;
 
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	
	int n,k;cin>>n>>k;
	string s1,s2;cin>>s1;
	
	for(int i=0;i<n&&k>0;i++)
	{
		int changenum=min(k,max(s1[i]-'a','z'-s1[i]));k-=changenum;
		
		s2+=((s1[i]+changenum>'z') ? (s1[i]-changenum) : (s1[i]+changenum));
	}
	
	s2+=s1.substr(s2.size());
	
	cout<<(k==0 ? s2 : "-1");
	
	//printf("Time used = %.12f",(double)(clock())/CLOCKS_PER_SEC);
	return 0;
}