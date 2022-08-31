n = int(input())

arr = sorted(list(map(int,input().split())))

if arr[n-1] > 0:
    print ('1 ' + str (arr[0]))
    print ('1 ' + str (arr[n-1]))

    res = '';
    for i in arr[1:n-1]:
        res += ' ' + str (i)
    print (str(n-2) + res)
else:
    print ('1 ' + str (arr[0]))
    print ('2 ' + str (arr[1]) + ' ' + str(arr[2]))

    res = '';
    for i in arr[3:]:
        res += ' ' + str(i)
    print (str(n-3) + res)