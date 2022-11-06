#By: Luogu@rui_er(122461)
x = eval(input())

def gen_bf(x):
    expr = ""
    for i in range(x+48):
        expr += "+"
    expr += ".[-]"
    return expr

bf = ""
if x >= 100:
    bf += gen_bf(x//100)
    bf += gen_bf(x//10%10)
    bf += gen_bf(x%10)
elif x >= 10:
    bf += gen_bf(x//10)
    bf += gen_bf(x%10)
else:
    bf += gen_bf(x)
print(bf)