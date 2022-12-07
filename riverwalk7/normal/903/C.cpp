#include <iostream>
#include <fstream>
#include <map>
using namespace std;
int N, a;
int ans;
map<int, int> m;
int main()
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>a;
        m[a]++;
        ans = max(ans, m[a]);
    }
    cout<<ans<<endl;
}