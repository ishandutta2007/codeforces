#include<bits/stdc++.h>
using namespace std;
int cnt[1000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;int n;
    cin>>n;
    cin>>s;
    for (auto x:s)cnt[x]++;
    vector<int> vec;while(cnt['o'] && cnt['n'] && cnt['e'])vec.push_back(1),cnt['o']--,cnt['n']--,cnt['e']--;

    while(cnt['z'] && cnt['e'] && cnt['r'] && cnt['o'])vec.push_back(0),cnt['z']--,cnt['e']--,cnt['r']--,cnt['o']--;
    for (char a='a';a<='z';a++) {
        if (cnt[a]){
            cout<<-1<<endl;
            return 0;
        }
    }
    for (auto x:vec)cout<<x<<' ';
    cout<<endl;
}