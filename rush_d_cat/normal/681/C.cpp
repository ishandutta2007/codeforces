#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
priority_queue< int,vector<int>,greater<int> >q;
string s,res[1000000+10];
int k,cnt=0,num[1000000+10];
int main()
{
    std::ios::sync_with_stdio(false);
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        if(s=="insert")
        {
            cin>>k;
            res[++cnt]="insert";
            num[cnt]=k;
            q.push(k);
        }
        if(s=="removeMin")
        {
            if(q.size()==0)
            {
                res[++cnt]="insert";num[cnt]=1;
                res[++cnt]="removeMin";
            }else{
                res[++cnt]="removeMin";
                q.pop();
            }
        }
        if(s=="getMin")
        {
            cin>>k;
            while(true)
            {
                if(q.size()==0)
                {
                    res[++cnt]="insert";num[cnt]=k;
                    res[++cnt]="getMin";num[cnt]=k;
                    q.push(k);
                    break;
                }
                if(q.top()>k)
                {
                    res[++cnt]="insert";num[cnt]=k;
                    res[++cnt]="getMin";num[cnt]=k;
                    q.push(k);
                    break;
                }
                if(q.top()<k)
                {
                    res[++cnt]="removeMin";
                    q.pop();
                }
                if(q.top()==k)
                {
                    res[++cnt]="getMin";num[cnt]=k;
                    break;
                }
            }
        }
    }
    cout<<cnt<<endl;
    for(int i=1;i<=cnt;i++)
    {
        if(res[i]=="insert"||res[i]=="getMin") cout<<res[i]<<" "<<num[i]<<endl;
        else cout<<res[i]<<endl;
    }
    return 0;
}