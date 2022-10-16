#include <cstdio>
#include <algorithm>
const int Inf=0x3f3f3f3f;
int x[4],y[4];
int num_x,num_y;
int lx[4],ly[4];
int bx[4],by[4];
int xy[4][4],xy_len[4];
int yx[4][4],yx_len[4];
int ax[4],ay[4];
int ans;
void update_ans(){
    int d[4][4];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            d[i][j]=std::abs(bx[i]==bx[j]?by[i]-by[j]:bx[i]-bx[j]);
        }
    }
    if(d[0][1]!=d[0][2]||d[0][1]!=d[3][1]||d[0][1]!=d[3][2]){
        return;
    }
    int p[4];
    for(int i=0;i<4;i++){
        p[i]=i;
    }
    do{
        int tmp_ans=0;
        for(int i=0;i<4;i++){
            if(x[i]!=bx[p[i]]&&y[i]!=by[p[i]]){
                tmp_ans=Inf;
                break;
            }
            tmp_ans=std::max(tmp_ans,std::abs(x[i]-bx[p[i]]+y[i]-by[p[i]]));
        }
        if(tmp_ans<ans){
            for(int i=0;i<4;i++){
                ax[i]=bx[p[i]];
                ay[i]=by[p[i]];
            }
            ans=tmp_ans;
        }
    }while(std::next_permutation(p,p+4));
}
void calc(){
    if(num_x==2&&num_y==2){
        bx[0]=lx[0],by[0]=ly[0];
        bx[1]=lx[0],by[1]=ly[1];
        bx[2]=lx[1],by[2]=ly[0];
        bx[3]=lx[1],by[3]=ly[1];
        update_ans();
        return;
    }
    if(num_y==1){
        bx[0]=lx[0],by[0]=ly[0];
        bx[1]=lx[1],by[1]=ly[0];
        bx[2]=lx[0],by[2]=ly[0]+(lx[0]-lx[1]);
        bx[3]=lx[1],by[3]=ly[0]+(lx[0]-lx[1]);
        update_ans();
        bx[2]=lx[0],by[2]=ly[0]-(lx[0]-lx[1]);
        bx[3]=lx[1],by[3]=ly[0]-(lx[0]-lx[1]);
        update_ans();
        return;
    }
    if(num_x==1){
        bx[0]=lx[0],by[0]=ly[0];
        bx[1]=lx[0],by[1]=ly[1];
        bx[2]=lx[0]+(ly[0]-ly[1]),by[2]=ly[0];
        bx[3]=lx[0]+(ly[0]-ly[1]),by[3]=ly[1];
        update_ans();
        bx[2]=lx[0]-(ly[0]-ly[1]),by[2]=ly[0];
        bx[3]=lx[0]-(ly[0]-ly[1]),by[3]=ly[1];
        update_ans();
        return;
    }
    if(num_y==0){
        int d=std::abs(lx[0]-lx[1]);
        std::sort(xy[0],xy[0]+2);
        std::sort(xy[1],xy[1]+2);
        int a[4]={xy[0][0],xy[0][1]-d,xy[1][0],xy[1][1]-d};
        std::sort(a,a+4);
        int z=(a[0]+a[3])>>1;
        bx[0]=lx[0],by[0]=z;
        bx[1]=lx[0],by[1]=z+d;
        bx[2]=lx[1],by[2]=z;
        bx[3]=lx[1],by[3]=z+d;
        update_ans();
        return;
    }
    if(num_x==0){
        int d=std::abs(ly[0]-ly[1]);
        std::sort(yx[0],yx[0]+2);
        std::sort(yx[1],yx[1]+2);
        int a[4]={yx[0][0],yx[0][1]-d,yx[1][0],yx[1][1]-d};
        std::sort(a,a+4);
        int z=(a[0]+a[3])>>1;
        bx[0]=z,by[0]=ly[0];
        bx[1]=z+d,by[1]=ly[0];
        bx[2]=z,by[2]=ly[1];
        bx[3]=z+d,by[3]=ly[1];
        update_ans();
        return;
    }
}
void solve(){
    ans=Inf;
    for(int i=0;i<4;i++){
        scanf("%d%d",&x[i],&y[i]);
    }
    for(int mask=0;mask<16;mask++){
        num_x=0,num_y=0;
        for(int i=0;i<4;i++){
            xy_len[i]=yx_len[i]=0;
        }
        for(int i=0;i<4;i++){
            if((mask>>i)&1){
                int pos=-1;
                for(int j=0;j<num_x;j++){
                    if(lx[j]==x[i]){
                        pos=j;
                        break;
                    }
                }
                if(pos==-1){
                    lx[num_x++]=x[i];
                    xy[num_x-1][xy_len[num_x-1]++]=y[i];
                }
                else{
                    xy[pos][xy_len[pos]++]=y[i];
                }
            }
            else{
                int pos=-1;
                for(int j=0;j<num_y;j++){
                    if(ly[j]==y[i]){
                        pos=j;
                        break;
                    }
                }
                if(pos==-1){
                    ly[num_y++]=y[i];
                    yx[num_y-1][yx_len[num_y-1]++]=x[i];
                }
                else{
                    yx[pos][yx_len[pos]++]=x[i];
                }
            }
        }
        if(std::max(num_x,num_y)!=2||(num_y==0&&xy_len[0]!=2)||(num_x==0&&yx_len[0]!=2)){
            continue;
        }
        calc();
    }
    if(ans==Inf){
        puts("-1");
    }
    else{
        printf("%d\n",ans);
        for(int i=0;i<4;i++){
            printf("%d %d\n",ax[i],ay[i]);
        }
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        solve();
    }
    return 0;
}