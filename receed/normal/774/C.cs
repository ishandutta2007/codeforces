using System;
class Program
{
    static void Main()
    {
        int n = Convert.ToInt32(Console.ReadLine());
        if(n%2==0){
            for (var i = 1; i*2<=n; ++i)
            { 
                    Console.Write("1");
            }
        }
        else{
            Console.Write("7");
            for (var i = 2; i*2<=n; ++i)
            { 
                    Console.Write("1");
            }
        }

    }

}