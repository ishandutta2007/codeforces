//
// Created by 54173 on 5/19/2022.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);

    int n,m; cin>>n>>m;
    int a[m], p[n];
    long long pref[n];
    long long sum = 0;
    for(int i=0;i<n;i++) {
        cin>>p[i];
        sum += p[i];
        pref[i] = sum;
    }
    for(int i=0;i<m;i++) {
        cin>>a[i];
    }
//    cout<<"?\n";
    sort(a,a+m);
    int pt1 = 0, pt2 = 0;
    //This is annoying :(
    sum = 0;
    long long ans = 0;
    for(int i=0;i<n;i++) {
        if(i*100 < a[0])
            sum += p[i];
    }
    ans = sum;
    sum = 0;
    for(int i=n-1;i>=0;i--) {
        if(i*100 > a[m-1])
            sum += p[i];
    }
    ans = max(ans,sum);
//    cout<<ans<<'\n';
    for(int i=0;i<m-1;i++) {
        //Now pt1 point to th first store "no before than i"
        while(pt1<n &&pt1*100 <= a[i])
            pt1++;
        if(pt1 > n) break;
        pt2 = pt1;
//        cout<<i<<' '<<pt1<<endl;
        while(pt1 < n && pt1*100 < a[i+1]) {
//            cout<<"YEAH\n";
            //This means next hut is possible
            int st = min(a[i+1],2*(pt1*100)-a[i]);
            pt2 = max(pt2,pt1);
            while(pt2 < n && pt2*100 - st < a[i+1]-pt2*100) {
                pt2++;
            }
            pt2--;
//            cout<<"M "<<pt1<<' '<<pt2<<' '<<st<<endl;
            ans = max(ans,pref[pt2]-pref[pt1]+p[pt1]);
            pt1++;
        }
    }
    cout<<ans;
    return 0;
}