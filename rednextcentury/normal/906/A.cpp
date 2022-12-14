#include<iostream>
using namespace std;
int tot = (1<<26) - 1;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int pos = tot;
    int ret = 0;
    int solved = 0;
    for (int i=0;i+1<n;i++){
        char x;
        cin>>x;
        string s;
        cin>>s;
        int val=0;
        for (int i=0;i<s.size();i++){
            val |= (1<<(s[i]-'a'));
        }
        if (x=='.'){
            pos = pos & (tot - val);
        } else if (x=='!'){
            if (solved)
                ret++;
            pos = pos & val;
        } else if (x=='?'){
            if (solved)
                ret++;
            pos = pos & (tot-val);
        }

        if (__builtin_popcount(pos)==1){
            solved = 1;

        }


    }
    string x;
    cin>>x>>x;
    cout<<ret<<endl;
}