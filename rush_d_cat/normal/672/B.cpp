#include<iostream>
using namespace std;
int main()
{
    int n;char a[1000000+2];
    cin>>n;
    scanf("%s",&a);
    if(n>26)
    {
        cout<<-1<<endl;
    }else{
        int cnt[27],ans=0;
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<strlen(a);i++)
        {
            if(cnt[a[i]-'a'+1]++);
        }
        for(int i=1;i<=26;i++){
            ans+=cnt[i];
            if(cnt[i]>=1) ans--;
        }
        cout<<ans<<endl;
    }
    return 0;
}