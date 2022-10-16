n,a,b=(int(z) for z in input().split())
if a*b<n:
    print(-1)
else:
    i=1
    s=''
    if b%2==1:
        while i<=n:
            if i%b!=0:
                s+=str(i)+' '
            else:
                print(s+str(i))
                s=''
            i+=1
        while i<=a*b:
            if i%b!=0:
                s+='0 '
            else:
                print(s+'0')
                s=''
            i+=1
    else:
        i=1
        r=1
        s=''
        while i<=n:
            if (i%b!=0 and r==1) or ((i-1)%b!=0 and r==-1):
                s+=str(i)+' '
                i+=r
            else:
                print(s+str(i))
                s=''
                i+=b
                r*=-1
        if i>n>i+r*b:
            while (i-1)%b!=0:
                if i <=n:
                    s+=str(i)+' '
                else:
                    s+='0 '
                i-=1
            print (s+str(i))
            s=''
            i+=b
        while i <=a*b:
            if i%b!=0:
                s+='0 '
            else:
                print (s+'0')
                s=''
            i+=1