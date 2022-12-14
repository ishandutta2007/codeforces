#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[10000];
int num[10000];
int ret[100][100];
vector<int> F;
vector<int> T;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n*n;i++)cin>>a[i], num[a[i]]++;
    int odd = 0;
    int o =-1;
    for (int i=0;i<=1000;i++){
        if (num[i]%2)odd++,o=i;
    }
    if (n%2==0){
        if (odd){
            cout<<"NO"<<endl;
            return 0;
        } else {
            for (int i=1;i<=1000;i++){
                while(num[i]>=4){
                    num[i]-=4;
                    F.push_back(i);
                }
                if (num[i]>=2){
                    T.push_back(i);
                }
            }
            for (int i=1;i<=n;i++){
                for (int j=1;j<=n;j++){
                    if (ret[i][j]!=0)continue;
                    if (F.empty()){
                        cout<<"NO"<<endl;
                        return 0;
                    }
                    int g = F.back();F.pop_back();
                    ret[i][j]=g;
                    ret[n-i+1][j]=g;
                    ret[n-i+1][n-j+1]=g;
                    ret[i][n-j+1]=g;
                }
            }
        }
    } else {
        if (odd>1){
            cout<<"NO"<<endl;
            return 0;
        } else {
            ret[n/2+1][n/2+1]=o;
            num[o]--;
            for (int i=1;i<=1000;i++){
                while(num[i]>=4){
                    num[i]-=4;
                    F.push_back(i);
                }
                if (num[i]>=2){
                    T.push_back(i);
                }
            }
            for (int i=1;i<=n;i++){
                for (int j=1;j<=n;j++){
                    if (i==n/2+1 && j==n/2+1)continue;
                    if (ret[i][j]!=0)continue;
                    int g;
                    if (i==n/2+1 || j==n/2+1){
                        if (T.empty() && F.empty()){
                            cout<<"NO"<<endl;
                            return 0;
                        } else if (T.empty()){
                            g=F.back();F.pop_back();
                            T.push_back(g);
                        } else {
                            g = T.back(); T.pop_back();
                        }
                    } else {
                        if (F.empty()){
                            cout<<"NO"<<endl;
                            return 0;
                        } else {
                            g = F.back(); F.pop_back();
                        }
                    }
                    ret[i][j]=g;
                    ret[n-i+1][j]=g;
                    ret[n-i+1][n-j+1]=g;
                    ret[i][n-j+1]=g;
                }
            }
        }
    }
    cout<<"YES"<<endl;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++)cout<<ret[i][j]<<' ';
        cout<<endl;
    }
}