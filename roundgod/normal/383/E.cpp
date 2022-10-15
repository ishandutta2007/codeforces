#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM (1<<24)
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,cnt[MAXM];
string str;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        cin>>str;
        cnt[1<<(str[0]-'a')]++;
        if(str[0]!=str[1]) cnt[1<<(str[1]-'a')]++;
        if(str[0]!=str[2]&&str[1]!=str[2]) cnt[1<<(str[2]-'a')]++;
        int mask1=0,mask2=0,mask3=0;
        mask1=(1<<(str[0]-'a'))+(1<<(str[1]-'a'));
        mask2=(1<<(str[0]-'a'))+(1<<(str[2]-'a'));
        mask3=(1<<(str[1]-'a'))+(1<<(str[2]-'a'));
        if(str[0]!=str[1]) cnt[mask1]--;
        if(mask1!=mask2&&str[0]!=str[2]) cnt[mask2]--;
        if(mask1!=mask3&&mask2!=mask3&&str[1]!=str[2]) cnt[mask3]--;
        if(str[0]!=str[1]&&str[0]!=str[2]&&str[1]!=str[2]) cnt[(1<<(str[0]-'a'))+(1<<(str[1]-'a'))+(1<<(str[2]-'a'))]++;
    }
    for(int i=0;i<24;i++) 
		for(int mask=0;mask<(1<<24);mask++)
			if(mask&(1<<i))
				cnt[mask]+=cnt[mask^(1<<i)];
    int ans=0;
	for(int i=0;i<(1<<24);i++) ans^=cnt[i]*cnt[i];
	printf("%d\n",ans);
    return 0;
}