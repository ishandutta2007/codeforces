#include<bits/stdc++.h>
using namespace std;
multiset<int> s;
int main()
{
    int a,b,f,k;
    cin>>a>>b>>f>>k;
    int cur=b;
    int fuel=0;
    for (int i=0;i<k;i++)
    {
        if (i%2==0)
        {
            if (cur>=f)cur-=f;
            else{
                cout<<-1<<endl;
                return 0;
            }
            if (i+1<k && cur<(a-f)*2)
            {
                cur=b,fuel++;
            }
            if (i+1==k && cur<a-f)
                cur=b,fuel++;
            if (cur>=(a-f))
                cur-=a-f;
            else
            {
                cout<<-1<<endl;
                return 0;
            }
        }
        else
        {
            if (cur>=(a-f))cur-=a-f;
            else{
                cout<<-1<<endl;
                return 0;
            }
            if (i+1<k && cur<(f)*2)
            {
                cur=b,fuel++;
            }
            if (i+1==k && cur<f)
                cur=b,fuel++;
            if (cur>=(f))
                cur-=f;
            else
            {
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    cout<<fuel<<endl;
}