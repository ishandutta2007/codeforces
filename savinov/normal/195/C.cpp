#include <iostream>
#include <string>
#include <cstdio>
#include <stack>
using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    int n;
    cin >> n;
    getchar();
    bool flag = false;
    string ext;
    string s;
    stack <bool> a;
    for (int i=0;i<n;i++)
    {
        getline(cin,s);
        //cout << s << endl;
        for (int i=0;i<(int)s.length();i++)
        {
            if (s[i]=='t'&&s[i+1]=='r')
            {
                a.push(flag);
                break;
            }
            if (s[i]=='t'&&s[i+1]=='h')
            {
                flag = true;
                while (s[i]!='(') i++;
                while (!((s[i]>='a'&&s[i]<='z')||((s[i]>='A'&&s[i]<='Z')))) i++;
                while ((s[i]>='a'&&s[i]<='z')||((s[i]>='A'&&s[i]<='Z')))
                {
                    ext+=s[i];
                    i++;
                }
                break;
            }
            if (s[i]=='c')
            {
                if (a.top()==false)
                {

                string tmp;
                while (s[i]!='(') i++;
                while (!((s[i]>='a'&&s[i]<='z')||((s[i]>='A'&&s[i]<='Z')))) i++;
                while ((s[i]>='a'&&s[i]<='z')||((s[i]>='A'&&s[i]<='Z')))
                {
                    tmp+=s[i];
                    i++;
                }
                if (flag&&tmp==ext)
                {
                    while (s[i]!='"') i++;
                    i++;
                    while (s[i]!='"')
                    {
                        cout << s[i];
                        i++;
                    }
                    return 0;
                }
                }
                a.pop();
                break;
            }
        }
    }
    cout << "Unhandled Exception";
    return 0;
}