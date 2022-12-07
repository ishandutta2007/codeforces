#include <iostream>
#include <fstream>
#include <vector>
#define MAXN 200100
using namespace std;
int T, N;
int a[MAXN];
int freq[MAXN];
int cur_MEX, new_MEX;
vector<int> ans;
bool used[MAXN];
void solve()
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>a[i];
        freq[a[i]]++;
    }
    for(int i=0; i<=N; i++)
    {
        if(freq[i] == 0)
        {
            cur_MEX = i;
            break;
        }
    }
    int tot = cur_MEX;
    int new_MEX = cur_MEX;
    for(int i=0; i<N; i++)
    {
        freq[a[i]]--;
        if(a[i] < new_MEX && freq[a[i]] == 0)
        {
            new_MEX = a[i];
        }
        if(a[i] < cur_MEX && used[a[i]] == false)
        {
            used[a[i]] = true;
            --tot;
        }
        if(tot == 0)
        {
            for(int i=0; i<cur_MEX; i++)
            {
                used[i] = false;
            }
            ans.push_back(cur_MEX);
            cur_MEX = new_MEX;
            tot = cur_MEX;
        }
    }
    //reset at the end
    for(int i=0; i<N; i++)
    {
        used[i] = false;
        freq[i] = 0;
    }
    cout<<ans.size()<<endl;
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<""<<endl;
    ans.clear();
}
int main()
{
    cin>>T;
    for(int i=0; i<T; i++)
    {
        solve();
    }
}