#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <map>
#include <algorithm>
#define ll long long

using namespace std;

int kf[2000],plas[2000];
int kol=0;
string s;

int main()
{
    int a;
    scanf("%d",&a);
    cin>>s;
    int n=s.length(),i=0,sum=0,q;

    kf[0]=1;
    while (i<n) {
        if (s[i]=='-') {
            kf[kol]=-1;
            i++;
        }else if (s[i]=='+') {
            kf[kol]=1;
            i++;
        }
        if ((s[i]>='0')&&(s[i]<='9')){
            q=0;
            while ((s[i]>='0')&&(s[i]<='9')) {
                q=q*10+s[i]-'0';
                i++;
            }
            kf[kol]*=q;
            i++;
        }
        if (s[i]=='a') plas[kol]=0;
        else plas[kol]=1;
        i+=3;
        kol++;
    }

    for (int i=0;i<kol;i++) sum+=kf[i]*(a+plas[i]);
    sort(kf,kf+kol);
    for (int i=1;i<kol;i++) sum+=kf[i]*i;
    printf("%d",sum);
    return 0;
}