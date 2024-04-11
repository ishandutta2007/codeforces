#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

char s1[100005];
char s2[100005];

int main()
    {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%s", s1);
    scanf("%s", s2);

    int F1[26] = {};
    int F2[26] = {};

    for(int i=0; s1[i] != 0; i++)
        {
        F1[s1[i]-'A']++;
        }

    for(int i=0; s2[i] != 0; i++)
        {
        F2[s2[i]-'A']++;
        }

    int cnt[26] = {};
    int ans = 0;

    for(int i=0; s1[i] != 0; i++)
        {
        if(F1[s1[i]-'A'] > F2[s1[i]-'A'])
            {
            bool ok = 0;

            for(int ch='A'; ch<s1[i]; ch++)
                {
                if(F1[ch-'A'] < F2[ch-'A'])
                    {
                    ans++;
                    F1[s1[i]-'A']--;
                    F1[ch-'A']++;
                    s1[i] = ch;
                    ok = 1;
                    break;
                    }
                }

            if(ok==0)
                {
                if(cnt[s1[i] - 'A'] >= F2[s1[i] - 'A'])
                    {
                    for(int ch=s1[i]+1; ch<='Z'; ch++)
                        {
                        if(F1[ch-'A'] < F2[ch-'A'])
                            {
                            ans++;
                            F1[s1[i]-'A']--;
                            F1[ch - 'A']++;
                            s1[i] = ch;
                            break;
                            }
                        }
                    }
                }

            cnt[s1[i]-'A']++;
            }
        }

    printf("%d\n", ans);
    printf("%s\n", s1);

    return 0;
    }