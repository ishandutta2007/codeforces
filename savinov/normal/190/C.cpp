#include <iostream>
#include <stack>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    int n;
    cin >> n;
    getchar();
    stack <int> st;
    int count = 0;
    bool flag=true;
    string ans;
    bool eof=false;
    while (!eof)
    {
        string temp;
        char c;
        while((c=getchar())!=' '&&c!='\n')
        {
            temp+=c;
        }
        if (c=='\n')
        {
            eof=true;
        }

        if (flag)
        {
            if (temp=="pair")
            {
                st.push(0);
                ans+="pair<";
            }
            else ans+="int";
            flag=false;
        }
        else
        {
            if (st.empty()||st.top()==2)
            {
                cout << "Error occurred\n";
                return 0;
            }
            if (temp=="pair")
            {
                st.top()++;
                ans+="pair<";
                st.push(0);
            }
            else
            {
                if (count+1>n)
                {
                    cout << "Error occurred\n";
                    return 0;
                }
                count ++ ;
                if (st.top()==0)
                {
                    st.top()++;
                    ans+="int,";
                }
                else
                {
                    st.pop();
                    ans+="int>";
                    while (!st.empty()&&st.top()==2)
                    {
                        ans+=">";
                        st.pop();
                    }
                    if (!st.empty()) ans+=",";
                }

            }
        }


    }
    if (!st.empty())
    {
        cout << "Error occurred\n";
        return 0;
    }
    cout << ans << endl;
    return 0;
}