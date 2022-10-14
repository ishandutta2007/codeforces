//https://codeforces.com/contest/200/problem/A
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m,k,x,y,c,p;
    cin>>n>>m>>k;
    int arr[n][m],fr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            arr[i][j]=1;fr[i][j]=0;
        }
    }
   
    for(int i=0;i<k;i++){
       cin>>x>>y;
       if(arr[x-1][y-1]){
           cout<<x<<" "<<y<<"\n";arr[x-1][y-1]=0; 
           continue;
       }
       for (int p=-1;p<= 1;p++)
		 for (int j =-1;j<= 1;j++)
			if (x-1+p >= 0 && x-1+p<n && y-1+j >= 0 && y-1+j<m) {
					int d = fr[x+p-1][y+j-1]- abs(p)-abs(j);
					if (fr[x-1][y-1]<d)
						fr[x-1][y-1]=d;
				}
       int j=fr[x-1][y-1];
       while(1){
           c=0,p;
           for(int k=max(1-x,-j);k<=min(n-x,j);k++){
               p = j-abs(k);
               if(y-p>0&&arr[x+k-1][y-p-1]) {
                   cout<<x+k<<" "<<y-p<<"\n";arr[x+k-1][y-p-1]=0;c=1;break;
               }
                if(y+p<=m&&arr[x+k-1][y+p-1]) {
                   cout<<x+k<<" "<<y+p<<"\n";arr[x+k-1][y+p-1]=0;c=1;break;
               }
              
           }
           if(c==1) break;
           else {j++; fr[x-1][y-1]++;}
       }

       
    }
}