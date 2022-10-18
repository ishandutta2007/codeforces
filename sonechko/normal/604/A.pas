uses math;
var a1,a2,a3,a4,a5,l1,l2,l3,l4,l5,k1,k2,ans1,ans2:extended;
  begin
    read(a1,a2,a3,a4,a5,l1,l2,l3,l4,l5,k1,k2);
    ans1:=max(0.3*500,(1-a1/250)*500-50*l1)+
    max(0.3*1000,(1-a2/250)*1000-50*l2)+
    max(0.3*1500,(1-a3/250)*1500-50*l3)+
    max(0.3*2000,(1-a4/250)*2000-50*l4)+
    max(0.3*2500,(1-a5/250)*2500-50*l5)+k1*100-k2*50;
    writeln(ans1:0:0);
  end.