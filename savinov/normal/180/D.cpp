#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s,t;
    cin >> s >> t;
    int cnt[26];
    for(int i=0;i<26;i++)
        cnt[i] = 0;
    for(int i=0;i<(int)s.length();i++)
        cnt[s[i]-'a']++;
    int cur = -1;
    for(int i=0;i<(int)t.length();i++)
    {
        int a = 0;
        for(int j = t[i]-'a' + 1;j<26;j++)
            a+=cnt[j];
        if (a>0)
            cur = i;
        if (cnt[t[i]-'a']>0)
        {
            cnt[t[i]-'a']--;
            if (i==(int)t.length()-1&&s.length()>t.length())
                cur = (int)t.length();
        }
        else
            break;
    }
    if (cur==-1)
    {
        cout << "-1";
        return 0;
    }
    for(int i=0;i<26;i++)
        cnt[i] = 0;
    for(int i=0;i<(int)s.length();i++)
        cnt[s[i]-'a']++;
    for(int i=0;i<cur;i++)
    {
        cout << t[i];
        cnt[t[i]-'a']--;
    }
    if (cur<(int)t.length())
    {
        for(int j = t[cur]-'a' + 1;j<26;j++)
            if (cnt[j])
            {
                cout << (char)(j+'a');
                cnt[j]--;
                break;
            }
    }
    for(int i=0;i<26;i++)
        for(int j=0;j<cnt[i];j++)
            cout << (char)(i+'a');

    return 0;
}