alf = 'qwertyuioplkjhgfdsazxcvbnm'
for t in range(int(input())):
    n,a,b = map(int,input().split())
    st = alf[:b]
    st1 = st
    while len(st1) <= n:
        st1 += st
    print(st1[:n])