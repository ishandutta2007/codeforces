#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll arr[10101010];
ll dp[10101010];
ll brr[10101010];
string s;

int main()
{
	cin>>s;
	ll q=s.length();
	ll chk=0,i;
	if(q==0&&s[0]=='0')
	{
		printf("0");
		return 0;
	}
    for(i=1;i<=q-1;i++)
    {
        if(s[i]=='1') chk=1;
    }
    if(chk==0) printf("%lld",q/2);
	else printf("%lld",(q+1)/2);
}