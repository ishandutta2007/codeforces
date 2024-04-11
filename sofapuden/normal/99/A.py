l = input().split('.')
if l[0][-1] == '9':
    print('GOTO Vasilisa.')
else:
    if(l[1][0] >= '5'):
        print(int(l[0])+1)
    else:
        print(int(l[0]))