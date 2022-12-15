#include<iostream>

using namespace std;

#define MOD 1000000007

long long m,d;
string s;
long long dp[2001][2001][2][2][2];
//bool boo[2001][2001][2][2][2];

long long solve(long long pos,long long rem,bool even,bool equalS,bool started)
{
    //cout<<pos<<" "<<rem<<" "<<even<<" "<<equalS<<" "<<started<<endl;

    if(pos==0)
    {
        //cout<<rem<<endl;
        if(started && !rem)return 1;
        return 0;
    }
    if(dp[pos][rem][even][equalS][started]!=-1 && !equalS)return dp[pos][rem][even][equalS][started];

    long long digit=s[s.size()-pos]-'0';
    //cout<<digit<<endl;
    long long up=equalS==1?digit:9,i,newEven,newStarted,newEqualS;
    long long& res=dp[pos][rem][even][equalS][started];

    res=0;

    //cout<<up<<endl;
    if(even==0)
    {
        i=d;

        res=0;

        if(i<=up)
        {
            newStarted=i==0?started:1;
            newEven=newStarted?((even+1)%2):even;
            newEqualS=i==digit?equalS:0;

            res+=solve(pos-1,(rem*10+i)%m,newEven,newEqualS,newStarted);

            res%=MOD;

            //cout<<res<<" | "<<pos<<" "<<rem<<" "<<" "<<even<<" "<<equalS<<" "<<started<<endl;
        }

        return res;
    }

    for(i=0;i<=up;i++)
    {
        if(even==1 && i==d)
        {
            if(i!=0 || started)continue;
        }

        newStarted=i==0?started:1;
        newEven=newStarted?((even+1)%2):even;
        newEqualS=i==digit?equalS:0;

        res+=solve(pos-1,(rem*10+i)%m,newEven,newEqualS,newStarted);
    }

    res%=MOD;

    //cout<<res<<" | "<<pos<<" "<<rem<<" "<<" "<<even<<" "<<equalS<<" "<<started<<endl;

    return res;
}

string minusOne(string a)
{
    int i;

    for(i=a.size()-1;i>=0;i--)
    {
        //cout<<i<<endl;
        if(a[i]!='0')
        {
            a[i]--;
            break;
        }
        a[i]='9';
        //cout<<i<<endl;
    }

    if(a[0]=='0' && a.size()!=1)a.erase(0,1);

    return a;
}

int main ()
{
    string a,b;
    long long res,i,j;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>m>>d>>a>>b;

    s=b;

    for(i=0;i<=s.size();i++)
        for(j=0;j<m;j++)
            for(int j2=0;j2<2;j2++)
                for(int j3=0;j3<2;j3++)
                    for(int j4=0;j4<2;j4++)
                        dp[i][j][j2][j3][j4]=-1;

    res=solve(s.size(),0,1,1,0);
    //cout<<res<<" res"<<endl;

    if(a!="0")
    {
        s=minusOne(a);
        //cout<<s<<endl;
        res-=solve(s.size(),0,1,1,0);


    }

    while(res<0)res+=MOD;
    while(res>=MOD)res-=MOD;

    cout<<res<<endl;

    return 0;
}