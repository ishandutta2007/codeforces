#include<bits/stdc++.h>
using namespace std;
bool ok(string a,string b)
{
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    return a==b;
}
int n;
string a,b;
void shift(int x)
{
    cout<<x<<' ';
    reverse(a.begin(),a.end());
    reverse(a.begin()+x,a.end());
}
int main()
{
    cin>>n;
    cin>>a>>b;
    if (!ok(a,b))
    {
        cout<<"-1\n";
        return 0;
    }
    cout<<n*3<<endl;
    for (int i=0;i<n;i++)
    {
        int loc=-1;
        for (int j=0;j<n-i;j++){
            if (a[j]==b[i]){
                loc=j;
                break;
            }
        }
        loc=n-1-loc;
        shift(loc);
        shift(1);
        shift(n);
    }
    cout<<endl;
}