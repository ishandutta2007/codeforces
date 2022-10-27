#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const double INF = 100000;
typedef long long ll;
vector<ll> vec;
int main()
{
    ll a, b;
    cin >> a >> b;int ok = 1;
    vec.push_back(b);
    while(b>a)
    {
        if(b%10==1)
        {
            vec.push_back(b/10);
            b/=10;
        } else if(b%2==0)
        {
            vec.push_back(b/2);
            b/=2;
        } else{
            ok = 0;
            break;
        }
    }
    if(vec[vec.size()-1] != a) ok = 0;
    if(ok)
    {
        cout<<"YES"<<endl;
        cout << vec.size()<<endl;
        for(int i=vec.size()-1;i>=0;i--)
        {
            cout << vec[i];
            if(i==0) cout << endl;
            else cout<<" ";
        }
    } else {
        cout <<"NO"<<endl;
    }
}