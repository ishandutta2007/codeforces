t=int(input())
for i in range(t):
    n=int(input())
    s=input()
    num=s.count("?")
    if(num==n):
        s=""
        for i in range(n):
            if(i%2):
                s=s+"B"
            else:
                s=s+"R"
        print(s)
        continue
    while "?" in s:
        s=s.replace("???R","BRBR")
        if "?" not in s: break
        s=s.replace("R???","RBRB")
        if "?" not in s: break
        s=s.replace("?R","BR")
        if "?" not in s: break
        s=s.replace("?B","RB")
        if "?" not in s: break
        s=s.replace("B?","BR")
        if "?" not in s: break
        s=s.replace("R?","RB")
    print(s)