    #include <bits/stdc++.h>
    using namespace std;

    #define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    #define ll long long
    #define ii pair<ll,ll>
    #define all(x) x.be,x.ee
    #define le (x*2)
    #define ri (x*2+1)
    #define mid ((l+r)/2)
    #define ld long double
    #define e '\n'
    #define sp ' '
    #define pb push_back
    #define po pop_back()
    #define up upper_bound
    #define lo lower_bound
    #define in insert
    #define mk make_pair
    #define er erase
    #define R return
    #define se second
    #define co continue
    #define fi first
    #define fr front()
    #define ba back()
    #define si size()
    #define em empty()
    #define be begin()
    #define ee end()
    #define mod 1000000007
    #define eb 0.000000001
    #define pi acos(-1)

    int arr[6]={4,8,15,16,23,42},a[5],b[7];
    bool vis[110];
    pair<int,int> res[2020];

    int main(){
        for(int i=0;i<6;i++){
            for(int j=i+1;j<6;j++){
                res[arr[i]*arr[j]]=mk(arr[i],arr[j]);
            }
        }
        for(int i=0;i<4;i++){
            printf("? %d %d\n",i+1,i+2);
            fflush(stdout);
            scanf("%d",&a[i]);
        }
        int f=res[a[0]].fi, s=res[a[0]].se;
        if(a[1]%f==0&&(a[1]/f==res[a[1]].se||a[1]/f==res[a[1]].fi)) b[1]=f;
        else b[1]=s;
        b[0]=a[0]/b[1];
        b[2]=a[1]/b[1];
        b[3]=a[2]/b[2];
        b[4]=a[3]/b[3];
        for(int i=0;i<5;i++) vis[b[i]]=1;
        for(int i=0;i<6;i++){
            if(!vis[arr[i]]){
                b[5]=arr[i];
                break;
            }
        }
        printf("! %d %d %d %d %d %d\n",b[0],b[1],b[2],b[3],b[4],b[5]);
        fflush(stdout);
        R 0;
    }