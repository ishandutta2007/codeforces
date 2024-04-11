s=input()
x=s.count('VK')
n=len(s)
if s[0:2]=='KK' or s[n-2:n]=='VV':
    print(x+1)
else:
    b=s.find('VVV')
    c=s.find('KKK')
    
    if b!=-1 or c!=-1:
        print(x+1)
    else:
        print(x)