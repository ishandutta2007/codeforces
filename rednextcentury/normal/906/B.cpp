#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > ret;
void get1(int n,int m)
{
    ret.resize(n+1,vector<int>(m+1));
    for (int i=1;i<=n;i++){
        int x=1;
        for (int j=1+1-i%2;j<=m;j+=2)
            ret[i][x++]=(i-1)*m+j;
        for (int j=1+i%2;j<=m;j+=2)
            ret[i][x++]=(i-1)*m+j;
    }
    if (m==4){
        for (int j=1;j<=n/2;j++)
            swap(ret[j][3],ret[n-j+1][3]);
    }
}
vector<vector<int> > cur;
void get2(int n,int m)
{
    cur.resize(n+1,vector<int>(m+1));
    ret.resize(n+1,vector<int>(m+1));
    int c=1;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cur[i][j]=c++;
        }
    }
    for (int j=1;j<=m;j++){
        int x=1;
        for (int i=1+1-j%2;i<=n;i+=2)
            ret[x++][j]=cur[i][j];
        for (int i=1+j%2;i<=n;i+=2)
            ret[x++][j]=cur[i][j];
    }
    if (n==4){
        for (int i=1;i<=m/2;i++)
            swap(ret[3][i],ret[3][m-i+1]);
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    if (n==3 && m==3){
        cout<<"YES"<<endl;
        cout<<"1 3 4\n5 7 6\n9 2 8\n"<<endl;
    }
    else if (n==1 && m==1)
        cout<<"YES\n1\n"<<endl;
    else if (n==1 && m==4)
        cout<<"YES\n2 4 1 3\n";
    else if (n==4 && m==1)
        cout<<"YES\n2\n4\n1\n3\n";
    else if (n<=3 && m<=3){
        cout<<"NO"<<endl;
    } else {
        cout<<"YES"<<endl;
        if (n<m)
            get1(n,m);
        else
            get2(n,m);
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++)
                cout<<ret[i][j]<<' ';
            cout<<endl;
        }
    }

}