#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define pb push_back
int a[200010],n,S,T;vector<int> A;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i),S+=a[i];
	for(int i=0;i<n;i++)if(S-a[i]==(ll)a[i]*(n-1))A.pb(i+1);
	printf("%d\n",(int)A.size());
	for(int i=0;i<(int)A.size();i++)printf("%d%c",A[i],i==(int)A.size()-1?'\n':' ');
	return 0;
}