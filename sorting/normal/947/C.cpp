#include<iostream>
#include<map>

using namespace std;

struct trie
{
    long long mp,used,leftChild,rightChild;
};

long long cnt=1;

trie t[9000001];

long long a[9000001];

void update(long long x)
{
    long long st=1<<29,curr=0;

    while(st>0)
    {
        t[curr].mp++;
        if(st&x)
        {
            if(!t[curr].rightChild)
            {
                t[curr].rightChild=cnt;
                cnt++;
            }
            curr=t[curr].rightChild;
        }
        else
        {
            if(!t[curr].leftChild)
            {
                t[curr].leftChild=cnt;
                cnt++;
            }
            curr=t[curr].leftChild;
        }

        //mp[curr]++;
        st>>=1;
    }
    t[curr].mp++;
}

long long query(long long x)
{
    long long st=1<<29,curr=0,pr=0,i;

    for(i=0;i<30;i++)
    {
        if(x&st)
        {
            if(!t[curr].rightChild)
            {
                t[curr].rightChild=cnt;
                cnt++;
            }
            curr=t[curr].rightChild;
        }
        else
        {
            if(!t[curr].leftChild)
            {
                t[curr].leftChild=cnt;
                cnt++;
            }
            curr=t[curr].leftChild;
        }
        if(t[curr].mp==t[curr].used)
        {
            if(!(x&st))x+=st;
            else x-=st;
            curr=pr;
            i--;
            continue;
        }
        t[curr].used++;
        pr=curr;
        st>>=1;
    }

    return x;
}

int main ()
{
    long long n,i,x;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>x;

        a[i]=x;
    }

    for(i=0;i<n;i++)
    {
        cin>>x;

        update(x);
    }

    for(i=0;i<n-1;i++)
    {
        cout<<(a[i]^query(a[i]))<<" ";
    }
    cout<<(a[i]^query(a[i]))<<endl;

    return 0;
}