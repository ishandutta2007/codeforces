#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#define MAX_A 26
#define MAXN 100100
using namespace std;
int freq2[MAX_A][MAX_A]; //# of occurrences of ji after current position
int freq3[MAX_A][MAX_A]; //# of occurrences of suffix ji after current position
int freq6[MAX_A][MAX_A][MAX_A]; //# of occurrences of kji after current position
int T, N;
string s[MAXN];
vector<int> t[MAXN];
bool flag;
void reset_freq()
{
    for(int i=0; i<MAX_A; i++)
    {
        for(int j=0; j<MAX_A; j++)
        {
            freq2[i][j] = freq3[i][j] = 0;
            for(int k=0; k<MAX_A; k++)
            {
                freq6[i][j][k] = 0;
            }
        }
    }
    return;
}
bool palindrome(int x)
{
    if(t[x].size() == 1)
    {
        return true;
    }
    if(t[x].size() == 2)
    {
        if(t[x][0] == t[x][1])
        {
            return true;
        }
    }
    if(t[x].size() == 3)
    {
        if(t[x][0] == t[x][2])
        {
            return true;
        }
    }
    return false;
}
void solve()
{
    for(int i=N-1; i>=0; i--)
    {
        if(palindrome(i))
        {
            cout<<"YES"<<endl;
            reset_freq();
            return;
        }
        if(t[i].size() == 2)
        {
            freq2[t[i][1]][t[i][0]]++;
            freq3[t[i][1]][t[i][0]]++;
        }
        if(t[i].size() == 3)
        {
            freq3[t[i][2]][t[i][1]]++;
            freq6[t[i][2]][t[i][1]][t[i][0]] = 0;
        }
    }
    for(int i=0; i<N; i++)
    {
        if(t[i].size() == 1)
        {
            cout<<"YES"<<endl;
        }
        if(t[i].size() == 2)
        {
            if(freq2[t[i][0]][t[i][1]] || freq3[t[i][0]][t[i][1]])
            {
                cout<<"YES"<<endl;
                reset_freq();
                return;
            }
            freq2[t[i][1]][t[i][0]]--; freq3[t[i][1]][t[i][0]]--;
        }
        if(t[i].size() == 3)
        {
            if(freq6[t[i][0]][t[i][1]][t[i][2]])
            {
                cout<<"YES"<<endl;
                reset_freq();
                return;
            }
            if(freq2[t[i][0]][t[i][1]])
            {
                cout<<"YES"<<endl;
                reset_freq();
                return;
            }
            freq3[t[i][2]][t[i][1]]--;
            freq6[t[i][2]][t[i][1]][t[i][0]]--;
        }
    }
    reset_freq();
    flag = !flag;
    if(flag)
    {
        reverse(t, t+N);
        for(int i=0; i<N; i++)
        {
            reverse(t[i].begin(), t[i].end());
        }
        solve();
    }
    else
    {
        cout<<"NO"<<endl;
        return;
    }

}
int main()
{
    cin>>T;
    for(int i=0; i<T; i++)
    {
        cin>>N;
        for(int j=0; j<N; j++)
        {
            cin>>s[j];
            for(int k=0; k<s[j].length(); k++)
            {
                t[j].push_back(s[j][k] - 'a');
            }
        }
        flag = false;
        solve();
        for(int j=0; j<N; j++)
        {
            t[j].clear();
            s[j] = "";
        }
    }
}