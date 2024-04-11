#include <iostream>
#include <queue>
using namespace std;
char a[210000];
deque<int> p;
deque<int> q;
int N;
int l;
int totald, totalr;
int main()
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>a[i];
        if(a[i]=='D')
        {
            p.push_back(i);
            totald++;
        }
        else
        {
            q.push_back(i);
            totalr++;
        }
    }
    int counter = 0;
    while(true)
    {
        if(totald==0)
        {
            cout<<'R'<<endl;
            return 0;
        }
        if(totalr==0)
        {
            cout<<'D'<<endl;
            return 0;
        }
        if(a[counter]=='D')
        {
            p.pop_front();
            p.push_back(counter);
            l=q.front();
            a[l]='0';
            q.pop_front();
            totalr--;
        }
        else if(a[counter]=='R')
        {
            q.pop_front();
            q.push_back(counter);
            l=p.front();
            a[l]='0';
            p.pop_front();
            totald--;
        }
        counter=(counter+1)%N;
    }
}