#include <cstdio>
int mp[105][105];
int row[105],line[105];
int mn(int a,int b){
    return a<b?a:b;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&mp[i][j]);
        }
    }
    if(n<m){
        for(int i=1;i<=n;i++){
            row[i]=(1<<30);
            for(int j=1;j<=m;j++){
                row[i]=mn(row[i],mp[i][j]);
            }
            for(int j=1;j<=m;j++){
                mp[i][j]-=row[i];
            }
        }
        for(int j=1;j<=m;j++){
            line[j]=(1<<30);
            for(int i=1;i<=n;i++){
                line[j]=mn(line[j],mp[i][j]);
            }
            for(int i=1;i<=n;i++){
                mp[i][j]-=line[j];
            }
        }
    }
    else{
        for(int j=1;j<=m;j++){
            line[j]=(1<<30);
            for(int i=1;i<=n;i++){
                line[j]=mn(line[j],mp[i][j]);
            }
            for(int i=1;i<=n;i++){
                mp[i][j]-=line[j];
            }
        }
        for(int i=1;i<=n;i++){
            row[i]=(1<<30);
            for(int j=1;j<=m;j++){
                row[i]=mn(row[i],mp[i][j]);
            }
            for(int j=1;j<=m;j++){
                mp[i][j]-=row[i];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j]!=0){
                return puts("-1"),0;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(row[i]>0){
            ans+=row[i];
        }
    }
    for(int j=1;j<=m;j++){
        if(line[j]>0){
            ans+=line[j];
        }
    }
    printf("%d\n",ans);
    for(int i=1;i<=n;i++){
        if(row[i]>0){
            for(int j=1;j<=row[i];j++){
                printf("row %d\n",i);
            }
        }
    }
    for(int j=1;j<=m;j++){
        if(line[j]>0){
            for(int i=1;i<=line[j];i++){
                printf("col %d\n",j);
            }
        }
    }
    return 0;
}