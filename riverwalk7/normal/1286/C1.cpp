#include <iostream>
#include <fstream>
#define MAXN 110
using namespace std;
string s;
int N;
int freq[MAXN][26];
int freq2[MAXN][26]; //strings with a certain length, the frequency of a given letter
int freq3[26];
int freq4[26];
char ans[MAXN];
int main()
{
    cin>>N;
    cout<<"? "<<1<<" "<<N<<endl;
    for(int i=0; i<N*(N+1)/2; i++)
    {
        cin>>s;
        for(int j=0; j<s.length(); j++)
        {
            freq[s.length()][s[j]-'a']++;
        }
    }
    if(N == 1)
    {
        cout<<"! "<<s<<endl;
        return 0;
    }
    cout<<"? "<<1<<" "<<N-1<<endl;
    for(int i=0; i<N*(N-1)/2; i++)
    {
        cin>>s;
        for(int j=0; j<s.length(); j++)
        {
            freq2[s.length()][s[j]-'a']++;
        }
    }
    for(int i=N; i>0; i--)
    {
        for(int j=0; j<26; j++)
        {
            freq3[j] = freq[i][j]-freq2[i-1][j];
            if(freq3[j] != freq4[j])
            {
                ans[i] = j+'a';
                ++freq4[j];
                break;
            }
        }
    }
    cout<<"! ";
    for(int i=1; i<=N; i++)
    {
        cout<<ans[i];
    }
    cout<<""<<endl;
}