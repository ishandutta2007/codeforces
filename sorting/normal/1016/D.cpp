#include<bits/stdc++.h>

using namespace std;

int matrix[101][101];
int a[101],b[101];

int n,m;

void solveRow(int x,int pos);
void solveCol(int x,int pos);

void solveCol(int x,int pos)
{
    //cout<<"Col "<<pos<<endl;
    int i;

    for(i=0;i<n;i++)
        if(a[i]&x)
        {
             //cout<<i<<" "<<pos<<endl;
            b[pos]^=x;
            a[i]^=x;
            matrix[i][pos]^=x;
            return;
        }


    for(i=0;i<n;i++)
    {
        if(!(matrix[i][pos]&x))
        {
             //cout<<i<<" "<<pos<<endl;
            b[pos]^=x;
            a[i]^=x;
            matrix[i][pos]^=x;
            solveRow(x,i);

            return;
        }
    }
}

void solveRow(int x,int pos)
{

    //cout<<"Row "<<pos<<endl;
    int i;

    for(i=0;i<m;i++)
        if(b[i]&x)
        {
             //cout<<pos<<" "<<i<<endl;
            a[pos]^=x;
            b[i]^=x;
            matrix[pos][i]^=x;
            return;
        }

    for(i=0;i<m;i++)
    {
        if(!(matrix[pos][i]&x))
        {
            //cout<<pos<<" "<<i<<endl;
            a[pos]^=x;
            b[i]^=x;
            matrix[pos][i]^=x;
            solveCol(x,i);

            return;
        }
    }
}

void solve(int ind)
{
    int x,i,j;

    x=1<<ind;

    for(i=0;i<n;i++)
        if(a[i]&x)
            solveRow(x,i);

    for(j=0;j<m;j++)
        if(b[j]&x)
            solveCol(x,j);
}

int main ()
{
    int i,j,x=0,y=0;

    cin>>n>>m;

    for(i=0;i<n;i++)
    {
        cin>>a[i];
        x^=a[i];
    }

    for(j=0;j<m;j++)
    {
        cin>>b[j];
        y^=b[j];
    }

    if(x!=y)
    {
        cout<<"NO\n";
        return 0;
    }

    for(i=0;i<32;i++)
    {
        //cout<<i<<"____"<<endl;
        solve(i);
    }

    cout<<"YES\n";

    for(i=0;i<n;i++)
    {
        for(j=0;j<m-1;j++)
            cout<<matrix[i][j]<<" ";
        cout<<matrix[i][j]<<"\n";
    }

    return 0;
}