#include<bits/stdc++.h>

#define y1 yzydfa



using namespace std;

typedef vector<int> VI;

template<typename U,typename V>inline void smax(U& a,V b){if(a<b) a=b;}





const int BT=1<<18;

struct RMQ_TREE{

  int s[BT<<1];

  void modify(int x,int y) {

    for(x+=BT,s[x]=y; x>1; x>>=1){

      s[x>>1]=max(s[x],s[x^1]);

    }

  }

  int calc(int x) {

    int ans=s[x+BT];

    for(x+=BT; x>1; x>>=1){

      if(!(x&1)) smax(ans,s[x|1]);

    }

    return ans;

  }

} tx,ty;



const int NN=202020;

set<int> sx,sy;

int posx[NN];

int posy[NN];

int flag[NN];





inline void place(int x,int y){

  posy[x]=y; 

  posx[y]=x;

  stack<int> st;

  int y1,z;

  while(sy.size()){

    if((y1=*sy.begin())>y) break;

    sy.erase(sy.begin());

    if(flag[y1]==0){

      st.push(y1);

      tx.modify(posx[y1],0);

    }

  }

  st.push(y);

  sx.insert(x);

  flag[y]=0;

  while(st.size()){

    y1=st.top();

    st.pop();

    z=tx.calc(posx[y1])+1;

    tx.modify(posx[y1],z);

    ty.modify(y1,z);

    sy.insert(y1);

  }

}



inline void remove(int x) {

  int x1, yy, r;

  stack<int> st;

  while(x--) {

    x1=*sx.begin();

    st.push(x1);

    sx.erase(sx.begin());

    ty.modify(posy[x1],0);

  }

  x=st.top();

  tx.modify(x,0);

  flag[posy[x]]=1;

  

  st.pop();

  while(st.size()){

    x1=st.top();

    st.pop();

    r=ty.calc(posy[x1])+1;

    tx.modify(x1, r);

    ty.modify(posy[x1], r);

    sx.insert(x1);

  }

}



int main() {

#ifndef ONLINE_JUDGE

  freopen("in.in","r",stdin);

  freopen("out.out","w",stdout);

#endif

  int n,m,i;

  int typ,x,y;

  scanf("%d%d",&n,&m);

  for(i=0; i<m; i++){

    scanf("%d%d",&typ,&x);

    if(typ==1){

      scanf("%d",&y);

      place(x,y-i+m);

    }else remove(x);

    printf("%d\n",tx.calc(0));

  }

  return 0;

}