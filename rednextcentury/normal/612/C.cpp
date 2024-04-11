# include<bits/stdc++.h>
using namespace std;
map<char,int> typ;
map<char,int> val;
stack<char> st;
int main()
{
    typ['<']=1,typ['(']=1,typ['[']=1,typ['{']=1;
    typ['>']=2,typ[')']=2,typ[']']=2,typ['}']=2;

    val['<']=1;
    val['(']=2;
    val['[']=3;
    val['>']=1;
    val[')']=2;
    val[']']=3;
    val['{']=val['}']=4;
    string s;
    cin>>s;
    int n=s.length();
    int ans=0;
    for (int i=0;i<n;i++)
    {
        if (typ[s[i]]==1)
            st.push(s[i]);
        else
        {
            if (st.empty())
            {
                cout<<"Impossible"<<endl;
                return 0;
            }
            else
            {
                if (val[st.top()]!=val[s[i]])
                    ans++;
                st.pop();
            }
        }
    }
    if (st.empty())
    cout<<ans<<endl;
    else
        cout<<"Impossible"<<endl;
}