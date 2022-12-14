#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long
#define F first
#define S second
#define PB push_back
#define MP make_pair
int pr[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
int ret=0;
bool query(int x)
{
    cout<<x<<endl;
    fflush(stdout);
    string p;
    cin>>p;
    if (p[0]=='y'){
        ret++;
        return 1;
    }
    return 0;
}
int main ()
{
    for (int i=0;i<15;i++)
    {
        if (query(pr[i]) && pr[i]*pr[i]<=100)
            query(pr[i]*pr[i]);
        if (ret>1){
            cout<<"composite"<<endl;
            return 0;
        }
    }
    if (ret>1)
        cout<<"composite"<<endl;
    else cout<<"prime"<<endl;
}