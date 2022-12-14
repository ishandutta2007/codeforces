#include<bits/stdc++.h>
using namespace std;
int main()
{
    multiset<int> D;
    multiset<int> R;
    int n;
    cin>>n;
    string s;
    cin>>s;
    for (int i=0;i<s.size();i++)
    {
        if (s[i]=='D')D.insert(i);
        else R.insert(i);
    }
    int cur=-1;
    while(1)
    {
        if (D.empty()){
            cout<<"R"<<endl;
            return 0;
        }
        else if (R.empty())
        {
            cout<<"D"<<endl;
            return 0;
        }
        int x,y;
        if (R.lower_bound(cur+1)!=R.end())
            x = *R.lower_bound(cur+1);
        else
            x = *R.begin();
        if (D.lower_bound(cur+1)!=D.end())
            y = *D.lower_bound(cur+1);
        else
            y = *D.begin();
        if ((x>cur && y>cur) || (y<=cur && x<=cur))
        {
            if (x<y)
                D.erase(y),cur=x;
            else R.erase(x),cur=y;
        }
        else if (x>cur)
            D.erase(y),cur=x;
        else if (y>cur)
            R.erase(x),cur=y;
    }

}