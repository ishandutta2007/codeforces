#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int T, N;
string s;
int ans;
vector<int> b;
int K;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>T;
    for(int i=0; i<T; i++)
    {
        cin>>N>>s;
        ans = 0;
        b.clear();
        K = N;
        for(int j=0; j<N; j++)
        {
            if(s[j] != s[(j+1)%N])
            {
                K = j;
                break;
            }
        }
        if(K == N)
        {
            if(N < 3)
            {
                cout<<0<<endl;
            }
            else
            {
                cout<<(N+2)/3<<endl;
            }
            continue;
        }
        else
        {
            int counter = 0;
            for(int j=K; counter < N; j = (j+1)%N)
            {
                if(s[j] != s[(j+1)%N])
                {
                    b.push_back(1);
                }
                else
                {
                    b[b.size()-1]++;
                }
                ++counter;
            }
        }
        for(int j=0; j<b.size(); j++)
        {
            ans += (b[j]/3);
        }
        cout<<ans<<endl;
    }
}