#include<bits/stdc++.h>
using namespace std;
int preMnX[1000000];
int preMxX[1000000];
int preMnY[1000000];
int preMxY[1000000];
int sufMnX[1000000];
int sufMxX[1000000];
int sufMnY[1000000];
int sufMxY[1000000];
int X[1000000];
int Y[1000000];
long long sol(long long A,long long B,long long C,long long D)
{
    return (B-A+1)*(D-C+1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        s='.'+s+'.';
        X[0]=0;
        Y[0]=0;
        for (int i=1; i<s.size(); i++)
        {
            X[i]=X[i-1];
            Y[i]=Y[i-1];
            if (s[i]=='W')
                Y[i]++;
            if (s[i]=='D')
                X[i]++;
            if (s[i]=='S')
                Y[i]--;
            if (s[i]=='A')
                X[i]--;
            preMnX[i]=min(preMnX[i-1],X[i]);
            preMxX[i]=max(preMxX[i-1],X[i]);
            preMnY[i]=min(preMnY[i-1],Y[i]);
            preMxY[i]=max(preMxY[i-1],Y[i]);
        }
        sufMnX[s.size()-1]=X[s.size()-1];
        sufMxX[s.size()-1]=X[s.size()-1];
        sufMnY[s.size()-1]=Y[s.size()-1];
        sufMxY[s.size()-1]=Y[s.size()-1];
        for (int i=s.size()-2; i>=0; i--)
        {
            sufMnX[i]=min(sufMnX[i+1],X[i]);
            sufMxX[i]=max(sufMxX[i+1],X[i]);
            sufMnY[i]=min(sufMnY[i+1],Y[i]);
            sufMxY[i]=max(sufMxY[i+1],Y[i]);
        }
        long long ret=1e18;
        for (int i=0; i+1<s.size(); i++)
        {
            long long LMnX = preMnX[i];
            long long LMxX = preMxX[i];
            long long RMnX = sufMnX[i];
            long long RMxX = sufMxX[i];
            long long LMnY = preMnY[i];
            long long LMxY = preMxY[i];
            long long RMnY = sufMnY[i];
            long long RMxY = sufMxY[i];
            ret=min(ret,sol(min(LMnX,RMnX-1),max(LMxX,RMxX-1),min(LMnY,RMnY),max(LMxY,RMxY)));
            ret=min(ret,sol(min(LMnX,RMnX+1),max(LMxX,RMxX+1),min(LMnY,RMnY),max(LMxY,RMxY)));
            ret=min(ret,sol(min(LMnX,RMnX),max(LMxX,RMxX),min(LMnY,RMnY-1),max(LMxY,RMxY-1)));
            ret=min(ret,sol(min(LMnX,RMnX),max(LMxX,RMxX),min(LMnY,RMnY+1),max(LMxY,RMxY+1)));
            ret=min(ret,sol(min(LMnX,RMnX),max(LMxX,RMxX),min(LMnY,RMnY),max(LMxY,RMxY)));
        }
        cout<<ret<<endl;
    }
}