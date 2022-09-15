a={}
for i in range(3):
    t=raw_input()
    if(t=="rock"):
        a[i]=1
    elif t=="scissors":
        a[i]=0
    elif t=="paper":
        a[i]=2
if((a[0]-a[1]+3)%3==1 and (a[0]-a[2]+3)%3==1):
    print "F";
elif((a[1]-a[0]+3)%3==1 and (a[1]-a[2]+3)%3==1):
    print "M"
elif((a[2]-a[1]+3)%3==1 and (a[2]-a[0]+3)%3==1):
    print "S"
else:
    print "?"