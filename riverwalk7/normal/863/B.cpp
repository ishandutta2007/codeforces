#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int w[100];
vector<int> v;
int ans;
int cur;
int main()
{
    cin>>N;
    for(int i=0; i<(2*N); i++)
    {
        cin>>w[i];
    }
    ans = 1e9;
    for(int i=0; i<(2*N); i++)
    {
        for(int j=i+1; j<(2*N); j++)
        {
            v.clear();
            cur = 0;
            for(int k=0; k<(2*N); k++)
            {
                if(k!=i&&k!=j)
                {
                    v.push_back(w[k]);
                }
            }
            sort(v.begin(), v.end());
            for(int k=0; k<(2*N-2); k+=2)
            {
                cur += (v[k+1]-v[k]);
            }
            ans = min(ans, cur);
        }
    }
    cout<<ans<<endl;
}