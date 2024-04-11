n=int(input())

for x in range(n):
    v=input()
    L=[]
    for bogstaver in (v):
        L.append(bogstaver)
    if L[-1] == 'o':
        print('FILIPINO')
    elif L[-1] == 'u':
        print('JAPANESE')
    else:
        print('KOREAN')