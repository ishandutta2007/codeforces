#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string.h>
using namespace std;
const double INF = 100000;
typedef long long ll;
int num[10],a[10],b[10];
string str[100000 +10], res[100000 + 10];
int used[100000 + 10];
int main()
{
    int i, n;
    for(i=1;i<=6;i++) cin>>num[i];
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        string s;
        cin>>s;
        if(s == "S") a[1]++,used[i]=1;
        if(s == "M") a[2]++,used[i]=1;
        if(s == "L") a[3]++,used[i]=1;
        if(s == "XL") a[4]++,used[i]=1;
        if(s == "XXL") a[5]++,used[i]=1;
        if(s == "XXXL") a[6]++,used[i]=1;
        
        if(s=="S,M") b[1]++;
        if(s=="M,L") b[2]++;
        if(s=="L,XL") b[3]++;
        if(s=="XL,XXL") b[4]++;
        if(s=="XXL,XXXL") b[5]++;
        str[i] = s;
    }
    int ok = 1;
    for(i=1;i<=6;i++)
    {
        if(num[i] < a[i]) ok=0;
        num[i] -= a[i];
    }
    if(!ok)
    {
        cout << "NO" << endl;
        return 0;
    }
        
    for(i = 1; i <= n; i++)
    {
        if(!used[i])
        {
            if(str[i] == "S,M")
            {
                if(num[1]>0) num[1]--,res[i]="S";
                else num[2]--,res[i]="M";
                b[1]--;
            }
            if(str[i] == "XXL,XXXL")
            {
                if(num[6]>0) num[6]--,res[i]="XXXL";
                else num[5]--,res[i]="XXL";
                b[5]--;
            }
        }
    }
    
    for(i = 1; i <= n; i++)
    {
        if(!used[i])
        {
            if(str[i] == "M,L")
            {
                if(num[2]>0) num[2]--,res[i]="M";
                else num[3]--,res[i]="L";
                b[2]--;
            }
            if(str[i] == "XL,XXL")
            {
                if(num[5]>0) num[5]--,res[i]="XXL";
                else num[4]--,res[i]="XL";
                b[4]--;
            }
        }
    }
    
    for(i = 1; i <= n; i++)
    {
        if(!used[i])
        {
            if(str[i] == "L,XL")
            {
                if(num[3]>0) num[3]--,res[i]="L";
                else num[4]--,res[i]="XL";
                b[3]--;
            }
        }
    }
    for(i=1;i<=6;i++)
    {
        if(num[i]<0) ok = 0;
    }
    if(!ok)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout << "YES" << endl;
    for(i = 1; i <= n; i++)
    {
        if(used[i]) cout<<str[i]<<endl;
        else{
            cout<<res[i]<<endl;
        }
    }
}