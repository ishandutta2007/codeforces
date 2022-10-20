//b
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 100001;
int n;
int a[N];
int b[3];

void Main(){
    int sigma = 0;
    for (int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    if (a[0]!=0) {cout<<-1<<endl;return;}
    for (int i=0;i<n;i++) sigma+=a[i];
    memset(b,0,sizeof(b));
    for (int i=0;i<n;i++) b[a[i]%3]++;
    
    if (sigma%3==0) {
        while (a[n-1]==0 && n-1!=0) n--;
        for (int i=n-1;i>=0;i--) cout<<a[i];
        cout<<endl;
        return;
    }
    
    if (sigma%3==1) {
        if (b[1]>=1 || b[2]>=2){
            if (b[1]>=1){
                int pos;
                for (pos=0;pos<n;pos++) if (a[pos]%3==1) break;
                while (n-1==pos || a[n-1]==0 && n-1!=0) n--;
                for (int i=n-1;i>=0;i--) if (i!=pos) cout<<a[i];
                cout<<endl;
            }
            else{
                int pos1,pos2;
                for (pos1=0;pos1<n;pos1++) if (a[pos1]%3==2) break;
                for (pos2=pos1+1;pos2<n;pos2++) if (a[pos2]%3==2) break;
                while (n-1==pos1 || n-1==pos2 || a[n-1]==0 && n-1!=0) n--;
                for (int i=n-1;i>=0;i--) if (i!=pos1 && i!=pos2) cout<<a[i];
                cout<<endl;
            }
            return;
        }
        else {
            cout<<-1<<endl;
            return;
        }
    }
    
    if (sigma%3==2) {
        if (b[2]>=1 || b[1]>=2){
            if (b[2]>=1){
                int pos;
                for (pos=0;pos<n;pos++) if (a[pos]%3==2) break;
                while (n-1==pos || a[n-1]==0 && n-1!=0) n--;
                for (int i=n-1;i>=0;i--) if (i!=pos) cout<<a[i];
                cout<<endl;
            }
            else{
                int pos1,pos2;
                for (pos1=0;pos1<n;pos1++) if (a[pos1]%3==1) break;
                for (pos2=pos1+1;pos2<n;pos2++) if (a[pos2]%3==1) break;
                while (n-1==pos1 || n-1==pos2 || a[n-1]==0 && n-1!=0) n--;
                for (int i=n-1;i>=0;i--) if (i!=pos1 && i!=pos2) cout<<a[i];
                cout<<endl;
            }
            return ;
        }
        else{
            cout<<-1<<endl;
            return;
        }
    }
    
}

int main(){
    while (cin>>n){
        Main();
    }
    return 0;
}