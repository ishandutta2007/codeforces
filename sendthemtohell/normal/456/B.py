from math import *
from sys import *
from decimal import *

s="00"+input()
x=int(s[-2]+s[-1])
if x%4:
    print(0)
else:
    print(4)